import pprint
import heapq
pp = pprint.PrettyPrinter(indent=4)


def ParseInput(filename):
    with open(filename, "r") as f:
        num_problems = int(f.readline())
        data = f.read()
        
    problems = []
    
    data = data.strip()
        
    lines = data.split("\n")
    
    current_line = 0
    for i in range(0, num_problems):
        this_problem_lines = int(lines[current_line])
        current_line+=1
        this_problem = lines[current_line:current_line+this_problem_lines]
        problems.append(this_problem)
        current_line = current_line+this_problem_lines
        
    return problems
        
        

def SolveProblem(problem):
    num_stars_got_on_level = {}
    one_star_list = []
    two_star_list = []
    current_level = 0
    for level in problem:
        (one_star, two_star) = [int(x) for x in level.split(" ")]
        two_star_list.append((two_star, current_level))
        num_stars_got_on_level[current_level] = 0
        one_star_list.append((one_star, -two_star, current_level))
        current_level +=1
        
    two_star_list.sort(reverse=True)
    one_star_list.sort(reverse=True)
    
    one_star_heap = []
    
    current_stars = 0
    num_steps = 0
    while len(two_star_list) > 0:
        easiest_two_star = two_star_list[-1]
        if easiest_two_star[0] <= current_stars:
            two_star_list.pop()
            stars_on_level = num_stars_got_on_level[easiest_two_star[1]]
            current_stars += (2 - stars_on_level)
            num_stars_got_on_level[easiest_two_star[1]] = 2
            num_steps += 1
        else:
            if len(one_star_heap) == 0 and len(one_star_list) == 0:
                return "Too Bad"
            while len(one_star_list) > 0 and one_star_list[-1][0] <= current_stars:
                doable_one_star = one_star_list.pop()
                heapq.heappush(one_star_heap, (doable_one_star[1], doable_one_star[2]))
            if len(one_star_heap) == 0:
                return "Too Bad"
            best_star = heapq.heappop(one_star_heap)
            stars_on_level = num_stars_got_on_level[best_star[1]]
            if stars_on_level == 0:
                num_stars_got_on_level[best_star[1]] = 1
                current_stars += 1
                num_steps += 1
                
    return num_steps
            
        
        
        
        


def SolveAndPrint(problems):
    current_problem = 1
    for problem in problems:
        answer = SolveProblem(problem)
        print ("Case #%d:" % current_problem), answer
        current_problem += 1
    
    
SolveAndPrint(ParseInput("B-large.in"))
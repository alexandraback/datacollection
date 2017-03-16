import pprint
pp = pprint.PrettyPrinter(indent=4)

n_choose_2 = {}
for i in range(0, 10):
    n_choose_2[i] = (i * (i-1))/2


def ParseInput(filename):
    with open(filename, "r") as f:
        f.readline()
        data = f.read()
        
    problems = []
    
    data = data.strip()
        
    for line in data.split("\n"):
        problem_data = line.split(" ")
        problem = [int(x) for x in problem_data]
        problems.append(problem)
        
#    pp.pprint(problems)
    return problems
        

def SolveProblem(problem):
    small, big = problem
    rotations_to_try = len(str(small)) - 1
    
    seen_numbers = {}
    num_recyclings = 0
    
    for test_num in range(small, big + 1):
        if test_num in seen_numbers:
            continue
        rot_str = str(test_num)
        current_rotation_list = {test_num : True}
        for i in range(0, rotations_to_try):
            rot_str = rot_str[1:] + rot_str[0]
            rot_num = int(rot_str)
            if small <= rot_num <= big:
                seen_numbers[rot_num] = True
                current_rotation_list[rot_num] = True
                
        num_recyclings += n_choose_2[len(current_rotation_list)]
                
    return num_recyclings
    


def SolveAndPrint(problems):
    current_problem = 1
    for problem in problems:
        answer = SolveProblem(problem)
        print ("Case #%d:" % current_problem), answer
        current_problem += 1
    
    
SolveAndPrint(ParseInput("C-large.in"))
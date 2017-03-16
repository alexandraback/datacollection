import pprint
pp = pprint.PrettyPrinter(indent=4)


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
    
    recyclings = {}
    
    for test_num in range(small, big + 1):
        rot_str = str(test_num)
        for i in range(0, rotations_to_try):
            rot_str = rot_str[1:] + rot_str[0]
            rot_num = int(rot_str)
            if rot_num > test_num and small <= rot_num <= big:
                recyclings[(test_num, rot_num)] = True
                
    return len(recyclings)
    


def SolveAndPrint(problems):
    current_problem = 1
    for problem in problems:
        answer = SolveProblem(problem)
        print ("Case #%d:" % current_problem), answer
        current_problem += 1
    
    
SolveAndPrint(ParseInput("C-small-attempt0.in"))
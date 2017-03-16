import pprint
pp = pprint.PrettyPrinter(indent=4)

def ParseInput(filename):
    problems = []
    with open(filename, "r") as f:
        num_problems = int(f.readline())
        for i in range(num_problems):
            current_problem = []
            current_problem.append([int(x) for x in f.readline().split(" ")])
            current_problem.append([int(x) for x in f.readline().split(" ")])
            problems.append(current_problem)
            
    return problems
        

def SolveProblem(problem):
    current_mote_size = problem[0][0]
    motes = sorted(problem[1], reverse = True)
    moves_so_far = 0
    fewest_moves = 10000
    if current_mote_size == 1:
        return len(motes)
    while len(motes) > 0:
        while len(motes) > 0 and current_mote_size > motes[-1]:
            current_mote_size += motes[-1]
            motes.pop()
        current_fewest = moves_so_far + len(motes)
        if current_fewest < fewest_moves:
            fewest_moves = current_fewest
        current_mote_size += current_mote_size - 1
        moves_so_far += 1
        
    return fewest_moves
    

def SolveAndPrint(problems):
    current_problem = 1
    for problem in problems:
        answer = SolveProblem(problem)
        print ("Case #%d:" % current_problem), answer
        current_problem += 1
    
    
SolveAndPrint(ParseInput("A-small-attempt0.in"))
import pprint
pp = pprint.PrettyPrinter(indent=4)

decoder = {' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'q': 'z', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q'}

def ParseInput(filename):
    with open(filename, "r") as f:
        f.readline()
        data = f.read()
        
    problems = []
    
    data = data.strip()
        
    for line in data.split("\n"):
        problems.append(line)
        
#    pp.pprint(problems)        
    return problems
        

def SolveProblem(problem):
    decoded = ""
    
    for echar in problem:
        decoded += decoder[echar]
        
    return decoded


def SolveAndPrint(problems):
    current_problem = 1
    for problem in problems:
        answer = SolveProblem(problem)
        print ("Case #%d:" % current_problem), answer
        current_problem += 1
    
    
SolveAndPrint(ParseInput("A-small-attempt0.in"))
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
        problem_data = [int(x) for x in problem_data]
        problem = [problem_data[0], problem_data[1], problem_data[2], problem_data[3:]]
        problems.append(problem)
        
    return problems
        

def SolveProblem(problem):
    googlers, surprises, score_to_get, score_list = problem
    
    combined_score_to_get = max(score_to_get * 3 - 2, score_to_get)
    combined_surprise_score_to_get = max(score_to_get * 3 - 4, score_to_get)
    
    total_scores_got = 0
    for score in score_list:
        if score >= combined_score_to_get:
            total_scores_got += 1
        elif score >= combined_surprise_score_to_get and surprises > 0:
            total_scores_got += 1
            surprises -= 1
    
    return total_scores_got


def SolveAndPrint(problems):
    current_problem = 1
    for problem in problems:
        answer = SolveProblem(problem)
        print ("Case #%d:" % current_problem), answer
        current_problem += 1
    
    
SolveAndPrint(ParseInput("B-large.in"))
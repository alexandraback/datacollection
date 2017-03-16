import pprint
pp = pprint.PrettyPrinter(indent=4)


def ParseInput(filename):
    with open(filename, "r") as f:
        f.readline()
        data = f.read()
        
    problems = []
    
    data = data.strip()
        
    lines = data.split("\n")
    i = 0
    while i < len(lines):
        (characters_entered, total_characters) = [int(x) for x in lines[i].split(" ")]
        character_probabilites = [float(x) for x in lines[i+1].split(" ")]
        problems.append([characters_entered, total_characters, character_probabilites])
        i+=2
        
    return problems
        

def SolveProblem(problem):
    characters_entered, total_characters, character_probabilites = problem
    best_expected_value = 100000000000000000000000000000000000
    
    current_success_prob = float(1)
    
    for characters_typed_used in range(1, characters_entered + 1):
        current_success_prob *= character_probabilites[characters_typed_used-1]
        backspaces = characters_entered - characters_typed_used
        num_rest_of_characters = total_characters - characters_typed_used
        success_characters = backspaces + num_rest_of_characters + 1
        failure_characters = success_characters + total_characters + 1
        
        this_expected_value = success_characters * current_success_prob + (1-current_success_prob) * failure_characters 
        
        if this_expected_value < best_expected_value:
            best_expected_value = this_expected_value
            
    return min(best_expected_value, float(total_characters) + 2)
        


def SolveAndPrint(problems):
    current_problem = 1
    for problem in problems:
        answer = SolveProblem(problem)
        print ("Case #%d:" % current_problem), answer
        current_problem += 1
    
    
SolveAndPrint(ParseInput("A-large.in"))
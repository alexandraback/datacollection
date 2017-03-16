with open("input.txt") as f:
    content = f.readlines()
    
number_of_testcases = int(content[0])

file = open('output.txt', 'w')

for case in range(0, number_of_testcases):
    array = content[case + 1].split("/")
    nenner = float(array[0])
    zaehler = float(array[1])
    
    answer = 0
    rest = nenner/zaehler
    lowest_possible = 0
    
    
    while (lowest_possible == 0):
            
        if (rest >= 0.5):
            answer = answer + 1
            lowest_possible = answer
            
        elif (rest < 0.5 and rest > 0):
            answer = answer + 1
            rest = rest * 2

    lowest_possible = answer
    
    while (rest != 0 and rest != 1 and answer <= 40):
            
        if (rest >= 0.5):
            rest = rest - 0.5
            
        elif (rest < 0.5):
            answer = answer + 1
            rest = rest * 2
    
    if (answer > 40):
        lowest_possible = -1
        file.write("Case #" + str(case+1) + ": impossible\n")
    else:
        file.write("Case #" + str(case+1) + ": " + str(lowest_possible) + "\n")
        
file.close()
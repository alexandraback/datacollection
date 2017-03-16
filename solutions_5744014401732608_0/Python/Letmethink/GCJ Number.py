import math

file = open('B-small-attempt1(1).in', 'r')
myList = file.readlines()
for count in range(len(myList)):
    myList[count] = myList[count].replace('\n', '')

inputs = int(myList[0])
myList.pop(0)

fout = open('output.out', 'w')
for count in range(inputs):
    choice = myList[count].split(' ')
    buildings = int(choice[0])
    ways = int(choice[1])
    drop = ''
    print(ways)
    print(buildings)
    if ways > math.pow(2, buildings-2):
        drop = 'IMPOSSIBLE'
    else:
        drop = 'POSSIBLE'

    if drop == 'POSSIBLE':
        grid = []
        for counter in range(buildings):
            option = []
            for counter2 in range(buildings):
                option.append(0)
            grid.append(option)

        used = 0
        binary = buildings - 2
        while ways > 0:
            answer = '1'
            for counter3 in range(binary):
                #print(math.pow(2, counter3+1))
                #print(used)
                if used % math.pow(2, counter3+1) >= math.pow(2, counter3):
                    answer = answer + str(counter3+2)
                counter3 += 1
            answer = answer + str(buildings)
            #print(answer)
            counter4 = 0
            past = 0
            #print('Route: ' + str(used+1))
            for decision in list(answer):
                if counter4+1 < len(answer):
                    #print(decision + ' to ' +  list(answer)[counter4+1])
                    grid[int(decision)-1][int(list(answer)[counter4+1])-1] = 1
                counter4 += 1
            used += 1
            ways -= 1
    #print(grid)
    output = 'Case #' + str(count+1) + ': ' + drop
    print(output)
    fout.write(output + '\n')
    newoutput = ''
    if drop == 'POSSIBLE':
        for item in grid:
            newoutput = ''
            for row in item:
                newoutput = newoutput + str(row)
            print(newoutput)
            fout.write(newoutput + '\n')
fout.close()
    
        

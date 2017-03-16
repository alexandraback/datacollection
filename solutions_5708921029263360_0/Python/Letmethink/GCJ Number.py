import math

file = open('C-small-attempt3.in', 'r')
myList = file.readlines()
for count in range(len(myList)):
    myList[count] = myList[count].replace('\n', '')

inputs = int(myList[0])
myList.pop(0)

fout = open('output.out', 'w')
for count in range(inputs):
    choice = myList[count].split(' ')
    times = int(choice[3])
    choice.pop()
    for counter in range(len(choice)):
         choice[counter] = int(choice[counter])
    choice = sorted(choice)
    shirts = int(choice[0])
    trousers = int(choice[1])
    jackets = int(choice[2])
    
    if jackets > times:
        if trousers == jackets:
            trousers = times
        if shirts == jackets:
            shirts = times
        jackets = times

    drop = str((shirts)*(trousers)*(jackets))
    output = 'Case #' + str(count+1) + ': ' + drop
    print(output)
    fout.write(output + '\n')


    for solution in range(int(drop)):
        shirtno = (solution%shirts)+1
        trouserno = (int(((solution - solution%shirts)/shirts)%trousers))+1
        jacketno = int((solution%(shirts*trousers*jackets))/(shirts*trousers))+1

        mysolution = str(shirtno) + ' ' + str(trouserno) + ' ' + str(jacketno)
        print(mysolution)
        fout.write(mysolution + '\n')
        
    
fout.close()
    
        

### Set the input and output file names
import time
import datetime
import math
filename = 'B-large'
input_filename = filename + '.in'
output_filename = filename + '.out.' + datetime.datetime.fromtimestamp(time.time()).strftime('%Y%m%d-%H%M%S') + '.txt'

def max_slides(m):
    result = []
    for i in range(m):
        row = [0]*(i+1) + [1]*(m-i-1)
        result.append(row)
    return result

def sumofp2(p):
    return [2**y for y,x in enumerate(bin(p)[:1:-1]) if int(x)]
    
### Open input file for reading
with open(input_filename) as f:
    lines = f.read().splitlines()

    ### Open output file for writing
    with open(output_filename, 'w') as output:

        ######################################################
        ### Initialise variables from first line of the file
        ######################################################   
        vars = lines[0].split(' ')
        cases = int(vars[0])                    # number of cases
        print(str(cases) + ' cases detected.')  # [soft validation]
        lineNum = 1                             # first case starts here
        caseNum = 0                             # for counting the num of cases
        caseSize_r = 1                          # number of rows in each case; default = 1
        caseSize_c = 1                          # number of columns in each case; default = 1
        
        #infoLines = True                        # Toggle according to question
        infoLines = False                       # Toggle according to question
        
        ### i.e. infoLines == True
        if infoLines:
            print('nope')
                
        ### i.e. infoLines == False
        else:   
            for caseNum in range(1, cases+1):
                city_buildings = int(lines[lineNum].split(' ')[0])
                city_routes = int(lines[lineNum].split(' ')[1])
                
                ### Do the Work!
                ### TODO!
                print('------------')
                myArr = max_slides(city_buildings)

                if city_routes > 2**(city_buildings-2):
                    possible = False

                elif city_routes == 2**(city_buildings-2):
                    possible = True
                    #if it is the limit, leave answer as max_slides
                else:
                    possible = True
                    # topleft of array:         myArr[0][0]
                    # bottomright of array:     myArr[city_buildings-1][city_buildings-1]
                    # topright of array:        myArr[0][city_buildings-1]
     
                    print(str(bin(city_routes)[:1:-1]))
                    #http://stackoverflow.com/questions/538346/iterating-over-a-string
                    
                    myArr[0] = [0]*city_buildings
                    
                    for i, c in enumerate(str(bin(city_routes)[:1:-1])):
                        #print('%d %s' % (i,c))
                        if int(c) == 1:
                            myArr[0][city_buildings-1-1-i] = 1
                        
                
                lineNum += 1
                
                ### Output myAns
                if possible:
                    print('Case #%d: POSSIBLE\n' % (caseNum))
                    output.write('Case #%d: POSSIBLE\n' % (caseNum))
                    for r in range(0, city_buildings):
                        print('%s' % (''.join(map(str,myArr[r]))))
                        output.write('%s\n' % (''.join(map(str,myArr[r]))))
                else:
                    print('Case #%d: IMPOSSIBLE\n' % (caseNum))
                    output.write('Case #%d: IMPOSSIBLE\n' % (caseNum))

                

### END

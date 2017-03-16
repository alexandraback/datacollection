import numpy

def read_words(afile):
    words = []
    for line in afile:
        words.append(line.strip())
    return words


filename = open('test3.txt' , 'r')
T = filename.readline() #num test cases
aList = read_words(filename) # array where each element is a line of text
for i in range(int(T)):
    
    DatBool = True
    Values = aList[i].split()
    R = int(Values[0])
    C = int(Values[1])
    M = int(Values[2])
    FR = 0
    FC = 0    
    
    Matrix = numpy.zeros(shape=(R,C))

    while ( (M >= (C-FC)) or (M >= (R-FR) ) ):    
        if ( (C-FC) <= (R-FR) ):
            FullRow = []
            for x in range (C):
                FullRow.append(1)
                    
            Matrix[FR] = FullRow
            M = M-(C-FC)
            FR += 1
            
        elif ( (C-FC) > (R-FR) ):        
            for o in range(R-FR):
                Matrix[(o+FR), (FC)] = 1
                
            M = M-(R-FR)
            FC += 1
        
    if (M==0):
        if (R==1 or C==1):
            win = 5
        elif ((R-FR)*(C-FC) == 1):
            win = 5
        elif ( (R-FR) == 1 ):
            
            DatBool = False
        elif ( (C-FC) == 1 ):
            
            DatBool = False
        #else:   done
    else: # some leftover m   M<(C-FC)  and M<(R-FR)
        if ( (R-FR) <= 2 ):
            
            DatBool = False
        if ( (C-FC) <= 2 ):
            
            DatBool = False
        else:  # at least a 3-by-3
            if (M  > ( (C-FC-2)*(R-FR-2) ) ):
                
                DatBool = False
            else: # winnable
                for z in range (C-FC-2):
                    if (M>0):
                        Matrix[(FR), (FC+z)] = 1
                        M -= 1
                if (M!=0):
                    for y in range (R-FR-3):
                        if (M>0):
                            Matrix[(FR+1+y), (FC)] = 1
                            M = M-1
        
    print "Case #"+str(i+1)+":"
    
    if (DatBool == False):
        print "Impossible"
    else:
        for r in range (R):
            DatRow = ""
            for c in range (C):
                if (Matrix[r][c] == 0):
                    DatRow += "."
                elif (Matrix[r][c] == 1):
                    DatRow += "*"
            if (r == (R-1)):
                DatRow = DatRow[:-1] + "c"
            print DatRow
                
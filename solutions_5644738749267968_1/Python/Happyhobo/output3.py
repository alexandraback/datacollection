def read_words(afile):
    words = []
    for line in afile:
            words.append(line.strip())
    return words

def FindIt(array, number):
    for z in range(len(array)):
        if (float(array[z]) > float(number)):
            return z
    

filename = open('Tim.txt' , 'r')
T = filename.readline() #num test cases
aList = read_words(filename) # array where each element is a line of text

for i in range(int(T)):

    NioMe = aList[i*3 + 1]
    Kent  = aList[i*3 + 2]
    N = NioMe.split()
    K = Kent.split()
    
    N = sorted(N)    
    K = sorted(K)
    
    KPoints = 0
    NPoints = 0
    
    for j in range(len(N)):
        if (float(N[0]) < float(K[0])):
            KPoints += 1
            del N[0]
            del K[-1]
        else:
            NPoints += 1
            del N[0]
            del K[0]
            
            
    NioMe2 = aList[i*3 + 1]
    Kent2  = aList[i*3 + 2]
    N2 = NioMe2.split()
    K2 = Kent2.split()
            
    N2 = sorted(N2)    
    K2 = sorted(K2)
            
    KPoints2 = 0
    NPoints2 = 0
            
    for k in range(len(N2)):
        if (float(N2[-1]) > float(K2[-1])):
            NPoints2 += 1
            del N2[-1]
            del K2[0]
        else:
            KPoints2 += 1
            x = FindIt(K2, N2[-1])
                
            del N2[-1]
            del K2[x]    
    
    print "Case #"+str(i+1)+": "+str(NPoints)+" "+str(NPoints2)
    
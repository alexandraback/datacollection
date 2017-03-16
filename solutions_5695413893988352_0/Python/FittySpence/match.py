global bestString
global bestDiff

def setEqual(str1, str2):
    for i in range(0, len(str1)):
        if str1[i] == -1 and str2[i] == -1:
            str1[i] = 0
            str2[i] = 0
        if str2[i] == -1:
            str2[i] = str1[i]
        if str1[i] == -1:
            str1[i] = str2[i]

def wantOneLess(str1, str2, i):
    if(i == 0):
        return
    if str1[i - 1] == -1 and str2[i - 1] == -1:
        str1[i - 1] = 0
        str2[i - 1] = 1
    if str1[i - 1] == -1:
        if str2[i - 1] != 0:
            str1[i - 1] = str2[i - 1] - 1
            return
        else:
            str1[i - 1] = 9
            wantOneLess(str1, str2, i - 1)
    if str2[i - 1] == -1:
        if str1[i - 1] != 9:
            str2[i - 1] = str1[i - 1] + 1
            return
        else:
            str2[i - 1] = 0
            wantOneLess(str1, str2, i - 1)
            
    

def solve(str1, str2, startingpoint):
    str1cop = copy(str1)
    str2cop = copy(str2)
    
    for i in range(0, len(str1)):
        
        if str1[i] > str2[i] and str2[i] > -1:
            for j in range(i + 1, len(str2)):
                if str1[j] == -1:
                    str1[j] = 0
                if str2[j] == -1:
                    str2[j] = 9
            for j in range(0, i):
                if str1[j] == -1 and str2[j] == -1:
                    str1[j] = 0
                    str2[j] = 0
                    continue
                if str1[j] == -1:
                    str1[j] = str2[j]
                if str2[j] == -1:
                    str2[j] = str1[j]
            firstDiff = takeDiff(str1, str2)
            firstString = getString(str1, str2)
            
            str1 = str1cop
            str2 = str2cop
            for j in range(i + 1, len(str2)):
                if str1[j] == -1:
                    str1[j] = 9
                if str2[j] == -1:
                    str2[j] = 0
                    
            #now want str1 exactly one less than str2
            wantOneLess(str1, str2, i)
            setEqual(str1, str2) 
            secondDiff = takeDiff(str1, str2)
            secondString = getString(str1, str2)
            
            if firstDiff < secondDiff:
                return firstString
            if firstDiff > secondDiff:
                return secondString
            if firstString < secondString:
                return firstString
            return secondString
            
            
        if str1[i] < str2[i] and str1[i] > -1:
            out = solve(str2, str1, startingpoint)
            return (out.split()[1] + " " + out.split()[0])
            
    setEqual(str1, str2)
    return getString(str1, str2)
            
    
def copy(str1):
    cop = []
    for i in str1:
        cop.append(i)
    return cop
    

    
def takeDiff(str1, str2): #no more question marks
    first = ""
    second = ""
    for i in range(0, len(str1)):
        first = first + str(str1[i])
        second = second + str(str2[i])
    
    num1 = int(first)
    num2 = int(second)
    if num1 > num2:
        return num1 - num2
    return num2 - num1
    
def getString(str1, str2):
    out = ""
    for i in range(0, len(str1)):
        out = out + str(str1[i])
    out = out + " "
    for i in range(0, len(str2)):
        out = out + str(str2[i])
    return out        
        
        
        
f = open('C:\\Users\\djspence\\Downloads\\B-small-attempt2.in', 'r')
tries = int(f.readline())

for ln in range(0, tries):
    st = f.readline().strip()
    str1tobe = st.split()[0]
    str2tobe = st.split()[1]
    
    str1 = []
    str2 = []
    for i in range(0, len(str1tobe)):
        if str1tobe[i] == "?":
            str1.append(-1)
        else:
            str1.append(int(str1tobe[i]))
        if str2tobe[i] == "?":
            str2.append(-1)
        else:
            str2.append(int(str2tobe[i]))
            
    #print(str1)
    #print(str2)
    soln = solve(str1, str2, 0)
    out = "Case #" + str(ln + 1) + ": " + soln
    print(out)
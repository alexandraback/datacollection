# File input
#input = open('H:/winprofile/desktop/a.in','r')
input = open('C:/Users/Asus/Desktop/b.in','r')
outputString = ""

#Define function
def check(array):
    for i in range(0,len(array)):
        for j in range(0,len(array[0])):
            x = array[i][j]
            #check horizontal
            p =[]
            for k in range(0,len(array)):
                if not k==i:
                    p.append(array[k][j])
            horizCheck = p==[] or max(p)<=x
            #check vertical
            p =[]
            for k in range(0,len(array[0])):
                if not k==j:
                    p.append(array[i][k])
            vertCheck = p==[] or max(p)<=x
            if not horizCheck and not vertCheck:
                return False
    return True
            
# Calculation
numCase = int(input.readline().replace('\n',''))
for i in range(1,numCase+1):
    array=[]
    size = input.readline().replace('\n','').split(' ')
    n = int(size[0])
    m = int(size[1])
    for j in range(0,n):
        line = input.readline().replace('\n','').split(' ')
        a=[]
        for k in line:
            a.append(int(k))
        array.append(a)

    if check(array):
        outputString = outputString + 'Case #' + str(i) + ': ' + 'YES' + '\n'
    else:
        outputString = outputString + 'Case #' + str(i) + ': ' + 'NO' + '\n'

#File output
#output = open('H:/winprofile/desktop/a.out','w')
output = open('C:/Users/Asus/Desktop/b.out','w')
output.write(outputString)
input.close()
output.close()

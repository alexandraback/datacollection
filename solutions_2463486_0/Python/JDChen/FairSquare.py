# File input
#input = open('H:/winprofile/desktop/a.in','r')
input = open('C:/Users/Asus/Desktop/c.in','r')
outputString = ""

#Define function
def countN(array,a,b):
    num = 0
    canCount = False
    for i in range(0,len(array)):
        if array[i]>b:
            return num
        elif canCount:
            num = num + 1
        elif array[i]>=a:
            canCount = True
            num = 1
    return num

def isPal(n):
    if n[0]=='0':
        return False
    for i in range(0,len(n)):
        if not n[i]==n[len(n)-1-i]:
            return False
    return True
            
# Calculation

pal=[]
pal.append('1')
pal.append('4')
pal.append('9')
p = []
for i in range(0,3):
    p.append(str(i)+str(i))
for i in range(0,3):
    for j in range(0,3):
        p.append(str(i)+str(j)+str(i))
for i in range(0,3):
    for j in range(0,3):
        p.append(str(i)+str(j)+str(j)+str(i))
for i in range(0,3):
    for j in range(0,3):
        for k in range(0,3):
            p.append(str(i)+str(j)+str(k)+str(j)+str(i))
for i in range(0,3):
    for j in range(0,3):
        for k in range(0,3):
            p.append(str(i)+str(j)+str(k)+str(k)+str(j)+str(i))
for i in range(0,3):
    for j in range(0,3):
        for k in range(0,3):
            for l in range(0,3):
                p.append(str(i)+str(j)+str(k)+str(l)+str(k)+str(j)+str(i))
for i in p:
    x=str(long(i)*long(i))
    if isPal(x):
        pal.append(x)
for i in range(0,len(pal)):
    pal[i]=long(pal[i])

#Read input
numCase = int(input.readline().replace('\n',''))
for i in range(1,numCase+1):
    line = input.readline().replace('\n','').split(' ')
    a = int(line[0])
    b = int(line[1])
    outputString = outputString + 'Case #' + str(i) + ': ' + str(countN(pal,a,b)) + '\n'


#File output
#output = open('H:/winprofile/desktop/a.out','w')
output = open('C:/Users/Asus/Desktop/c.out','w')
output.write(outputString)
input.close()
output.close()

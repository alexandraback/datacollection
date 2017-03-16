#author: Stanisław Kacprzak
inheritance=dict()
def inh(x,y):
    count=0
    for i in inheritance[x]:
        i=int(i)
        if i==y:
            count+=1
        else:
            count+=inh(i,y)
    return count

def search(classes):
    for x in range(1,classes+1):
        for y in range(1,classes+1):
            if x == y:
                continue
            if inh(x,y) > 1:
                return True
    return False

inputFile=open('input.in','r')
outputFile=open('output.txt','w')

testCases=int(inputFile.readline())
for n in range(1,testCases+1):
    inheritance=dict()
    classes=int(inputFile.readline())
    for i in range(1,classes+1):
        line=inputFile.readline().split(" ");
        inheritance[i]=line[1:]
    answer="Case #" + str(n)+": " 
    if search(classes):
        answer+="Yes"
    else:
        answer+="No"
    print(answer)
    outputFile.write(answer+"\n")
outputFile.close()           
        
            
            
        

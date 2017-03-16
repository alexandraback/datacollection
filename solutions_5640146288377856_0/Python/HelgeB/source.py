path = "C:/Users/Helge/Downloads/"
filename = "A-small-attempt0.in"
input_file = open(path+filename, 'r')
output = open(path + 'output', 'w')

numberOfTestcases = input_file.readline()
def readLineList():
    return input_file.readline().replace('\n', '').split(' ')

def writeOut(s, count):
    s = 'Case #' + str(count+1) + ': ' + s
    print(s)
    output.write(s + '\n')  

   
for i in range(0, int(numberOfTestcases)):
    [R,C,W] = list(map(int,readLineList()))
    result = str(int(ceil(C/W))+W-1)
    writeOut(str(result),i)

output.close()
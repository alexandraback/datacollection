input = open("B-small-practice.in", "rb")
output = open("B-small-output.txt", "wb")
t = int(input.readline().strip("\n\r"))
for i in range(t):
    case = 0
    a,b,k = [int(s) for s in input.readline().strip("\r\n").split()]
    for j in range(a):
        for s in range(b):
            result = j&s
            if(result < k):
            	case+=1
    output.write("Case #" + str(i + 1) + ": " + str(case) + "\n")
input.close()
output.close()

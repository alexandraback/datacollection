from fractions import gcd
import math
input = open("A-small.in", "rb")
output = open("A-small-output.txt", "wb")
t = int(input.readline().strip("\n\r"))
for i in range(t):
        line = input.readline().strip("\n\r")
        x,y = [int(s) for s in line.split("/")]
        n = gcd(x,y)
        x = x/n
        y = y/n
        l = [2**j for j in range(0,40)]
        if(y in l):
                count = int(math.log(y,2)) - len(bin(x)[2:])
                output.write("Case #" + str(i + 1) + ": " + str(count + 1) + "\n")
        else:
                output.write("Case #" + str(i + 1) + ": impossible\n")
input.close()
output.close()

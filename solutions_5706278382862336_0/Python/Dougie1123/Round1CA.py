
from fractions import Fraction
from numbers import Rational

def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

def is_power2(num):
	return num != 0 and ((num & (num - 1)) == 0)

f = open('A.txt')
lines = f.readlines()
f.close()

output = open('AOutput.txt','w')
for i in range(int(lines[0])):
    output.write("Case #" + str(i+1) + ": ")
    var = lines[i+1].split("/")
    num = int(var[0])
    d = int(var[1])
    common_div = gcd(num,d)
    new_d = d/common_div  
    new_num = num/common_div
    if(is_power2(new_d) == False):
	output.write("Impossible")
    else:
	p2num = len(bin(new_num))-3
	p2dom = len(bin(new_d))-3
	output.write(str(p2dom - p2num))

    output.write("\n")

#While method
#i = 0
#while (i < len(lines)-1):
    #var = lines[i+1].split()
    #output.write("Case #" + str(i+1) + ": ")
    #output.write("\n")
    #i += 1
    
output.close() 
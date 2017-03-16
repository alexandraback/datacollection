#3

print("Case #1: ")
#small test case
for i in range(3,103,2):
    s = "{0:b}".format(i)
    num = s + '0'*(16-2*len(s)) + s
    dividors = [str(int(s, b)) for b in range(2,11)]
    print(num + " " + " ".join(dividors))

#large test case
#for i in range(3,1003,2):
#    s = "{0:b}".format(i)
#    num = s + '0'*(32-2*len(s)) + s
#    dividors = [str(int(s, b)) for b in range(2,11)]
#    print(num + " " + " ".join(dividors))
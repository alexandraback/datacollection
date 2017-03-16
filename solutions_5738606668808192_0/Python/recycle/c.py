import sys

sys.stdout = open("out.txt", "w")



n = 16
j = 50

t = [3, 2, 5, 2, 7, 2, 9, 2, 11]
tstr = "3 2 5 2 7 2 9 2 11"

print("Case #1:")

for i in range(j):
    b = bin(i)[2:]

    s = ''
    for k in range(len(b)):
        s += b[k] + b[k]
    s = '1' + '0' * (n - 2 - len(s)) + s + '1'
    print(s, tstr)
    
    '''
    for k in range(2, 11):
        v = int(s, k)
        print(v, v % t[k-2])
    '''
sys.stdout.close()

from sys import stdin
def inefsol(x , y):
    ans = ''
    if y > 0:
        for _ in range(y):
            ans +='SN' 
    elif y < 0:
        for _ in range(-y):
            ans+= 'NS' 
    if x > 0:
        for _ in range(x):
            ans+= 'WE'
    elif x < 0:
        for _ in range(-x):
            ans+='EW'
    return ans
T = int(stdin.readline())
for t in range(1, T + 1):
    X,Y = [int(s) for s in stdin.readline().split()]
    print("Case #%d:" % t, inefsol(X, Y))
    

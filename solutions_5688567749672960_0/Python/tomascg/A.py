import sys



def foo(N):
    results = [0 for x in range(N+1)]
    for i in range(N,-1, -1):
        if i == N:
            results[i] = 0
        elif i == N-1:
            results[i] = 1
        else:
            b = reverse(i)
            if b <= i or b > N:
                results[i] = results[i+1]+1
            else:
                c = results[i+1]+1
                d = results[b]+1
                results[i] = min(c,d)
    return results[0]
            
    

def dp(a,N,memo):
    if a == N-1:
        return 1
    if a == N:
        return 0
    if a in memo:
        return memo[a]
    b = reverse(a)
    if b <= a or b > N:
        if a+1 in memo:
            c = memo[a+1]+ 1
        else:
            c = dp(a+1,N,memo)+ 1
        memo[a] = c
        return c
        
    else:
        if a+1 in memo:
            c = memo[a+1]+ 1
        else:
            c = dp(a+1,N,memo)+ 1
        if b in memo:
            d = memo[b] + 1
        else:
            d = dp(b, N,memo) + 1
        memo[a] = min(c,d)
        return memo[a]

def reverse(x):
    listed_number = list(str(x))
    listed_number.reverse()
    reversed_number = int("".join(listed_number))
    return reversed_number

sys.setrecursionlimit(30000000)

f = open("a.in", "r").read()

#new_file = open("sma.txt", "w")
splitted_file = f.split("\n")[:]

lineCounter =1
amountOfLines = len(splitted_file)

case = 0

while(lineCounter < amountOfLines-1):
    case += 1
    firstLine = splitted_file[lineCounter]
    lineCounter += 1

    N = int(firstLine)

    out = foo(N)
    print "Case "+ "#"+str(case) +": " + str(out)
    
    

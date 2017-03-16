#GCJ1B - A

inp = open("test.txt")
outp = open("output-test.txt", "w")

def solve(T, test):
    global outp
    #print(test, file=outp, end = '')
    test = [int(x) for x in test.split()]
    n = test[0]
    test.pop(0)
    s = sum(test)
    res = []
    for i in test:
        res.append(2/n - i/s)
    print('Case #' + T + ': ' + ' '.join([str(min(max(100*x, 0), 100)) for x in res]), file = outp)
    return 0

test = inp.readlines()
T = int(test[0])
for i in range(T):
    solve(str(i+1), test[i+1])
    

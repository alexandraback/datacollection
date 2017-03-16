



T = raw_input()
T = int(T)

for i in range(T):
    N = raw_input()
    N = int(N)

    lonely_numbers = []
    for j in range(2*N-1):
        line = raw_input()
        line = [int(h) for h in line.split()]
        for h in line:
            if h in lonely_numbers:
                lonely_numbers.remove(h)
            else:
                lonely_numbers.append(h)
    
    lonely_numbers.sort()
    ln = [str(h) for h in lonely_numbers]
            
    print("Case #%d: %s" % (i + 1, ' '.join(ln)))

    



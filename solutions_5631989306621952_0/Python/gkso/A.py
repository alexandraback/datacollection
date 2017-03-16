



T = raw_input()
T = int(T)

for i in range(T):
    S = raw_input()

    SS = S[0]

    for c in S[1:]:
        if c >= SS[0]:
            SS = c + SS
        else:
            SS = SS + c
    
    print("Case #%d: %s" % (i + 1, SS))

    



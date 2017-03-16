T = int(input())
for t in range(0, T):
    coders, jammers = input().split()
    coders = list(coders)
    jammers = list(jammers)
    minimize_coders = False
    minimize_jammers = False
    for i in range(0, len(coders)):
        if (minimize_coders == False) and (minimize_jammers == False) and (coders[i] != '?') and (jammers[i] != '?'):
            if coders[i] < jammers[i]:
                minimize_jammers = True
            elif coders[i] > jammers[i]:
                minimize_coders = True
        if minimize_coders:
            if coders[i] == '?':
                coders[i] = '0'
            if jammers[i] == '?':
                jammers[i] = '9'
        elif minimize_jammers:
            if jammers[i] == '?':
                jammers[i] = '0'
            if coders[i] == '?':
                coders[i] = '9'
        else:
            if (coders[i] == '?') and (jammers[i] == '?'):
                coders[i] = '0'
                jammers[i] = '0'
            elif coders[i] == '?':
                coders[i] = jammers[i]
            elif jammers[i] == '?':
                jammers[i] = coders[i]
    print("Case #" + str(t+1) + ": " + "".join(coders) + ' ' + "".join(jammers))

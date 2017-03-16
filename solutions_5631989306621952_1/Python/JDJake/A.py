T = int(input(""))

for i in range(1,T+1):
    S = input("")

    if len(S) == 1:
        print("Case #%d: %s" % (i, S))

    else:
        constructed = S[0]

        for s in list(S)[1:]:
            if (ord(s) >= ord(constructed[0])): constructed = s + constructed
            else: constructed = constructed + s

        print("Case #%d: %s" % (i, constructed))
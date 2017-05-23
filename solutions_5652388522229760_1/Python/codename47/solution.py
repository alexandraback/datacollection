fhr = open("input.in",'r')
f = fhr.readlines()
T = int(f[0].strip())
for i in range(1,T+1):
    S = set()
    N = int(f[i].strip())
    if N == 0:
        print("Case #" + str(i) + ": INSOMNIA")
    else:
        Asleep = 0
        counting = N
        while len(S)<10:
            S.update(list(str(counting)))
            Asleep = counting
            counting += N
        print("Case #" + str(i) + ": " + str(Asleep))

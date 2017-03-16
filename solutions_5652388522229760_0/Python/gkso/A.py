



T = raw_input()
T = int(T)

for i in range(T):
    N = raw_input()
    N = int(N)
    if N == 0:
        print("Case #%d: INSOMNIA" % (i + 1))
        continue

    flag = 0
    NN = 0
    while flag != 0b1111111111:
        NN += N
        # set flag
        X = NN
        while X != 0:
            Y = X % 10
            flag = flag | (1 << Y)
            X = X / 10
    
    print("Case #%d: %d" % (i + 1, NN))

    






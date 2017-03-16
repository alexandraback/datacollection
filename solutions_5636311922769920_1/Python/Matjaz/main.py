def output(testCase,answer):
    outputLine = "Case #"+str(testCase)+": "
    if type(answer) == str:
        outputLine += answer
    else:
        outputLine += " ".join(answer)
    print outputLine

T = int(raw_input())

for t in range(1,T+1):
    raw_data = raw_input()
    data = raw_data.split(" ")
    K = int(data[0])
    C = int(data[1])
    S = int(data[2])
    if S * C < K:
        output(t,"IMPOSSIBLE")
    else:
        location = 1
        locations = []
        for i in range(1,K+1):
            location = K * (location - 1) + i
            if i % C == 0:
                locations.append(str(location))
                location = 1

        if K % C != 0:
            i = K
            while True:
                location = K * (location - 1) + 1
                i += 1
                if i % C == 0:
                    locations.append(str(location))
                    break


        output(t,locations)




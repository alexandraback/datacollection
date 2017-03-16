import fileinput

data = fileinput.input()
T = int(data[0])
for t in range(T):
    K,C,S = (int(s) for s in data[t+1].split())
    if S*C < K:
        print("Case #{}: IMPOSSIBLE".format(t+1))
    else:
        states = []
        idx = 1
        while idx <= K:
            cnt = 1
            state = 0
            while cnt < C:
                if idx < K:
                    state += (idx-1)*(K**(C-cnt))
                cnt += 1
                idx += 1
            state += (idx if idx < K else K)
            states.append(state)
            idx += 1
        print("Case #{}: ".format(t+1)+" ".join(str(x) for x in states))


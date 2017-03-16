def helper(cp, it):
    ts = cp[:it + 1][::-1].replace('+', '=').replace('-', '+').replace('=', '-')
    ts += cp[it + 1:]
    return ts


def flip(pc):
    cp = pc
    count = 0
    it = len(cp) - 1
    while True:
        if cp[it] == '+':
            if it == 0:
                break
            it -= 1
            continue
        else:  # last is -
            if cp[0] == '-':
                cp = helper(cp, it)

                count += 1
                if it == 0:
                    break
                it -= 1
            else:   # first is +
                temp_it = it - 1
                while cp[temp_it] == '-':
                    temp_it -= 1
                cp = helper(cp, temp_it)
                cp = helper(cp, it)
                count += 2
                it -= 1
    return count

ln = int(input())
for i in range(ln):
    data = input()
    print("Case #" + str(i+1) + ": " + str(flip(data)))

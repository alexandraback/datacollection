T = int(input())
test = 1


def valid_train(temp):
    appear = []
    for char in temp:
        if char in appear:
            return False
        appear.append(char)
    return True


def shorter(temp):
    last = ""
    out = ""
    for char in temp:
        if char != last:
            out += char
            last = char
    return out


def training(pre, remaining):
    if len(remaining) == 0:
        # print(pre)
        return 1
    ways = 0
    for t in remaining:
        if pre == "":
            new_list = remaining[:]
            new_list.remove(t)
            ways += training(pre + t, new_list)
        else:
            if t[0] == pre[-1] or t[0] not in pre:
                can = True
                for char in t[1:]:
                    # print("char: ", char, t)
                    if char in pre:
                        can = False
                        break
                if can:
                    # print("can", pre, t)
                    new_list = remaining[:]
                    new_list.remove(t)
                    ways += training(pre + t, new_list)
    return ways

while test <= T:
    print("Case #" + str(test) + ": ", end="")
    test += 1

    n = int(input())
    trains = [shorter(i) for i in input().split()]
    # print(trains)

    not_valid = False
    for t in trains:
        if not valid_train(t):
            not_valid = True
            break

    if not_valid:
        print(0)
        continue

    count = training("", trains)
    print(count)

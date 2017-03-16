def last(inp):
    result = inp[0:1]

    for i in range(1, len(inp)):
        if inp[i] >= result[0]:
            result = inp[i:i + 1] + result
        else:
            result = result + inp[i:i + 1]
    return result


if __name__ == "__main__":

    tc = int(input())

    for k in range(tc):
        s = input()
        print("Case #{}: {}".format(k + 1, last(s)))

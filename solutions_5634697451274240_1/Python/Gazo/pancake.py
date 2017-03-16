t = int(input())
for i in range(1, t + 1):
    input_line = raw_input()
    first = input_line[0]
    rest = input_line[1:]

    if input_line[-1] == "-":
        count = 1
    else:
        count = 0

    for j in rest:
        if first != j:
            count += 1
        first = j

    print("Case #{}: {}".format(i, count))

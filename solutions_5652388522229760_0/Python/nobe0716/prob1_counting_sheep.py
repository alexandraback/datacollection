f = open('1.in')
for t in range(int(f.readline())):
    n = int(f.readline())
    v = 0

    condition_set = set()
    history_set = set()
    exit_condition = True
    while exit_condition:
        v += n
        condition_set |= set(str(v))
        if len(condition_set) == 10:
            break

        if v in history_set:
            break
        if v * 100 in history_set:
            break
        history_set.add(v)

    if len(condition_set) == 10:
        print("Case #%d: %d" % (t + 1, v))
    else:
        print("Case #%d: INSOMNIA" % (t + 1))


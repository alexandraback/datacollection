f_in = open('1.in')
f_out = open("1.out", "w")

for t in range(int(f_in.readline())):
    n = int(f_in.readline())
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
        # print("Case #%d: %d" % (t + 1, v))
        f_out.write("Case #%d: %d\n" % (t + 1, v))
    else:
        # print("Case #%d: INSOMNIA" % (t + 1))
        f_out.write("Case #%d: INSOMNIA\n" % (t + 1))
f_out.close()


#!/usr/bin/python

t = int(raw_input())

for i in range(t):
    val = int(raw_input())
    bool_arr = [False] * 10
    ans = val
    while not all(bool_arr):
        temp_val = str(ans)
        bool_arr = [(bool_arr[j] or str(j) in temp_val) for j in range(10)]
        if not any(bool_arr[1:]):
            break
        ans += val
    else:
        print "Case #" + str(i + 1) + ": " + str(ans - val)
        continue
    print "Case #" + str(i + 1) + ": INSOMNIA"

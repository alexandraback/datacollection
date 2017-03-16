#! /usr/bin/python -tt 

T = input()
f = open("out", "w")
for Case in range(1, T+1):
    aLine = raw_input()
    aLine = aLine.split()
    A = eval(aLine[0])
    B = eval(aLine[1])
    aLine = raw_input()
    aLine = aLine.split()
    co_rate = []
    for i in range(len(aLine)):
        co_rate.append(eval(aLine[i]))
    ans = 3000000
    con_co_rate = [1.0]
    tmp_rate = 1
    for i in range(len(co_rate)):
        tmp_rate *= co_rate[i]
        con_co_rate.append(tmp_rate)
    for i in range(A+1):
        exp_key = 0
        key = i + i + B - A + 1
        rate = con_co_rate[A-i]
        exp_key = rate * key + (1-rate) * (key + B + 1)
        print 'exp_key =', exp_key
        if exp_key < ans:
            ans = exp_key
    if B + 2 < ans:
        ans = B + 2
    print con_co_rate
    f.write("Case #%d: %f\n" % (Case, ans))

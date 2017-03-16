for i in range(input()):
    c, f, x = map(float, raw_input().split())
    rate = 2
    total_time = 0
    next_wo = x * 1.0 / rate
    next_w = c / rate + x / (rate + f)
    while next_wo > next_w:
        total_time += c / rate
        rate += f
        next_wo = x * 1.0 / rate
        next_w = c / rate + x / (rate + f)
    total_time += next_wo
    print "Case #{}: {}".format(i + 1, total_time)

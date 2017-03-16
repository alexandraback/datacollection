__author__ = 'Shailesh'

with open("../files/B-small-attempt0.in", 'r') as input, open("../files/output.txt", 'w') as output:
    t = int(input.readline())
    for i in xrange(t):
        answer = "Case #" + str(i+1) + ": "
        c, f, x = map(float, input.readline().split())
        rate = 2
        time = 0
        gain = x/rate - x/(rate + f)
        loss = c/rate
        while gain > loss:
            rate += f
            time += loss
            gain = x/rate - x/(rate + f)
            loss = c/rate
        time += x/rate
        output.write(answer + str(time) + "\n")
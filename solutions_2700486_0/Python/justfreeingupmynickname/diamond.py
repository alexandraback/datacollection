from math import factorial as fact

fin = open("diam.in")
out = open("diam.out", "w")

num_tests = int(fin.readline())

for i in xrange(num_tests):
    num_diams, x, y = map(int, fin.readline().strip().split())

    min_lay = 0
    max_lay = 10000
    while min_lay != max_lay:
        mid = (min_lay + max_lay + 1)/2
        if mid*(2*mid-1) > num_diams:
            max_lay = mid-1
        else:
            min_lay = mid

    layer = min_lay+1
    our_layer = (abs(x) + y)/2 + 1
    level = y+1
    fallen = num_diams - ((layer-1)*(2*layer - 3))

    print layer, our_layer, level, fallen

    if our_layer > layer:
        out.write("Case #" + str(i+1) + ": 0.0\n")
        print("Case #" + str(i+1) + ": 0.0\n")
    elif our_layer < layer:
        out.write("Case #" + str(i+1) + ": 1.0\n")
        print("Case #" + str(i+1) + ": 1.0\n")
    elif x == 0:
        out.write("Case #" + str(i+1) + ": 0.0\n")
        print("Case #" + str(i+1) + ": 0.0\n")
    elif fallen >= 2*(layer-1) + level:
        out.write("Case #" + str(i+1) + ": 1.0\n")
        print("Case #" + str(i+1) + ": 1.0\n")
    else:
        prob = 0.0
        for x in xrange(level, fallen+1):
            prob += (fact(fallen) / float(fact(x) * fact(fallen - x)))
        prob /= 2**fallen
        out.write("Case #" + str(i+1) + ": " + str(prob) + "\n")
        print("Case #" + str(i+1) + ": " + str(prob) + "\n")
out.close()
fin.close()

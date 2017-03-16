file = open('B-small-attempt0.in')
for tc in range(1, int(file.readline())+1):
    E, R, N = [int(w) for w in file.readline().split()]
    values = [int(w) for w in file.readline().split()]
    if R > E:
        R = E
    gain = E * max(values)
    values.remove(max(values))
    for value in values:
        gain += R * value
    print ('Case #{0}: {1}'.format(tc, gain))

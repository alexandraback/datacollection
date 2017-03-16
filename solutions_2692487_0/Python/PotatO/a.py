def osmos(size, food):
    print "begin", size, food
    if size > max(food) or len(food) == 0:
        return 0;
    if size == 1:
        return len(food);
    while size > min(food):
        for i in reversed(xrange(len(food))):
            if food[i] < size:
                size += food[i]
                food.pop(i)
        if len(food) == 0:
            return 0
    food_l = len(food)
    if food_l == 1:
        return 1
    temp = osmos(size*2-1, food)
    om = min(1+temp, food_l)
    return om

f = open('a-small.in')
o = open('a-small.out', 'w')

n = int(f.readline())
for i in range(n):
    a, k = [int(c) for c in f.readline().split()]
    v = [int(c) for c in f.readline().split()]
    o.write('Case #%d: %d\n' % (i+1, osmos(a, v)))
o.close()
f.close()

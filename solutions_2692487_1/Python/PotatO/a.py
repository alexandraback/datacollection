def osmos(size, food):
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
    food_min = min(food)
    add = 0
    while (size <= food_min):
        add += 1
        size = size*2-1
    om = min(add+osmos(size, food), food_l)
    return om

f = open('a-large.in')
o = open('a-large.out', 'w')

n = int(f.readline())
for i in range(n):
    a, k = [int(c) for c in f.readline().split()]
    v = [int(c) for c in f.readline().split()]
    o.write('Case #%d: %d\n' % (i+1, osmos(a, v)))
o.close()
f.close()

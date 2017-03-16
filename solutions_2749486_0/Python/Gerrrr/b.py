def solve_case(case):
    target_x, target_y = case
    x, y = 0, 0
    path = ""
    step = 1
    while x != target_x:
        if x < target_x:
            if path == "" or path[-1] == "E":
                x -= step
                path += "W"
                step += 1
            elif path[-1] == "W":
                x += step
                path += "E"
                step += 1
        elif x > target_x:
            if path == "" or path[-1] == "E":
                x -= step
                path += "W"
                step += 1
            elif path[-1] == "W":
                x += step
                path += "E"
                step += 1
    if y != target_y:
        if y + step > target_y:
            while y + step > target_y:
                y -= step
                step += 1
                path += "S"
        elif y + step < target_y:
            while y + step < target_y:
                y += step
                step += 1
                path += "N"
        #if y < target_y:
        #    y += step
        #    path += "N"
        #    step += 1
        #elif y > target_x:
        #    y -= step
        #    path += "S"
        #    step += 1
        #print 'after mod2', x, y, step
        while y != target_y:
            if not path or path[-1] == "N":
                y -= step
                path += "S"
                step += 1
            elif path[-1] == "S":
                y += step
                path += "N"
                step += 1
    return path

input_file = "input_b"
input_file = "/Users/gerrrr/Downloads/B-small-attempt1 (1).in"
#input_file = "/Users/gerrrr/Downloads/A-large (1).in"
with open(input_file) as f:
    f.readline()
    cases = [map(int, x.split()) for x in f.readlines()]


#for case in cases:
#    print case
#    print solve_case(case)
for i, r in enumerate(map(solve_case, cases)):
    print 'Case #%s: %s' % (i + 1, r)

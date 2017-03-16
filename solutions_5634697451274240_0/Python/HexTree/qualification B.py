with open("data.txt", 'r') as f:
    with open("data1.txt", 'w') as g:
        T = int(f.readline())
        for j in range(T):
            pancakes = f.readline().strip()
            i = 0
            old = '!'
            counter = 0
            while i < len(pancakes):
                if pancakes[i] != old:
                    counter += 1
                old = pancakes[i]
                i += 1
            if pancakes[-1] == '+':
                counter -= 1
            g.write("Case #%d: %d\n" % ((j+1), counter))

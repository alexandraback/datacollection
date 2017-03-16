import fileinput

with open('output.txt', 'w') as f:
    T = None
    counter = 0
    for line in fileinput.input():
        if T is None:
            T = int(line.rstrip('\n'))
        else:
            counter += 1
            line = line.rstrip('\n')
            s_max, string = line.split(' ')
            liste = map(int, string)
            curr_clap = 0
            n_friends = 0
            for i, s_i in enumerate(liste):
                if i <= curr_clap:
                    curr_clap += s_i
                else:
                    n_friends += (i - curr_clap)
                    curr_clap += (s_i + i - curr_clap)
            f.write('Case #%d: %d\n' % (counter, n_friends))

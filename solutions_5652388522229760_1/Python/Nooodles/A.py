### Google code jam 2016
### Qualification round
### Counting sheep

Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1),

    N = int(raw_input());
    if (N == 0):
        print "INSOMNIA";
    else:
        ToDo = [1]*10;
        i = 0;
        while (sum(ToDo) != 0):
            i += 1;
            current = N*i;
            while (current > 0):
                ToDo[current%10] = 0;
                current /= 10;
        print i*N;

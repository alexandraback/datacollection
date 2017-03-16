### Google code jam 2016
### Qualification round
### Flipping pancakes

def changes(data):
    ans = 0;
    for i in range(len(data)-1):
        if (data[i] != data[i+1]):
            ans += 1;
    return ans

Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1),

    data = raw_input().split()[0] + '+';

    print changes(data);
    

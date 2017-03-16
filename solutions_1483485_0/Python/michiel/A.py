d = {}
d['y'] = 'a';d['e'] = 'o'; d['q'] = 'z';d['z'] ='q';
d['p'] = 'r';d['m'] = 'l'; d['s'] = 'n';d['l'] ='g';
d['j'] = 'u';d['c'] = 'e'; d['k'] = 'i';d['d'] ='s';
d['x'] = 'm';d['v'] = 'p'; d['n'] = 'b';d['r'] ='t';
d['i'] = 'd';d['b'] = 'h'; d['t'] = 'w';d['a'] ='y';
d['h'] = 'x';d['w'] = 'f'; d['f'] = 'c';d['o'] = 'k';
d['u'] = 'j';d['g'] = 'v';

N = int(raw_input())
for t in xrange(N):
    message = raw_input()
    new_message ="".join([ d.get(x,x) for x in message])
    print "Case #%d: %s" % (t+1,new_message)


#!/usr/bin/python
import sys

def build_map_g2s():
    g_cases = [
        'ejp mysljylc kd kxveddknmc re jsicpdrysi',
     	'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd',
     	'de kr kd eoya kw aej tysr re ujdr lkgc jv' ]
    
    s_cases = [ 
    	'our language is impossible to understand',
    	'there are twenty six factorial possibilities',
    	'so it is okay if you want to just give up' ]
    
    map_g2s = {}
    map_g2s['y']='a'
    map_g2s['e']='o'
    map_g2s['q']='z'
    map_g2s['z']='q'

    for n in xrange(3):
    	g = g_cases[n]
    	s = s_cases[n]
    	for i in xrange(len(g)):
    		map_g2s[g[i]]=s[i]
    
    return map_g2s

#---------------------------------------------
map_g2s = build_map_g2s()
T = int(sys.stdin.readline().strip())
x=1
while x <= T:
    G = sys.stdin.readline().strip()
    S = ''
    for i in xrange(len(G)):
        S += map_g2s[G[i]]
    print "Case #%d: %s" %(x, S)
    x += 1
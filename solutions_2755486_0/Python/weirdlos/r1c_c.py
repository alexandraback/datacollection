# Encoding: utf-8
'''
Created on 12.05.2013

@author: Los

@version: 0.0.1
'''
import sys

class cWall(object):
    def __init__(self):
        self.segments=list()
    def get_height(self, point):
        res=0
        for seg in self.segments :
            if seg[0]<=point<=seg[1] :
                res=max(res,seg[2])
        return res
    def build(self, x, y, s):
        self.segments.append((x,y,s))
    def attack(self, x, y, s):
        z=x
        while z<=y :
            if self.get_height(z) < s :
                return 1
            z+=0.5
        return 0
        

def main(argv=None):
    if argv==None : argv=sys.argv

    import locale
    locale.setlocale(locale.LC_ALL, '')

    T = int(input())
    for k in range(1, T + 1):
        wall=cWall()
        N=int(input().strip())
        d=list()
        n=list()
        w=list()
        e=list()
        s=list()
        delta_d=list()
        delta_p=list()
        delta_s=list()
        last_d=list()
        shedule=dict()
        counter=0
        for i in range(N) :
            l=input().strip().split()
            d.append(int(l[0]))
            n.append(int(l[1]))
            w.append(int(l[2]))
            e.append(int(l[3]))
            s.append(int(l[4]))
            delta_d.append(int(l[5]))
            delta_p.append(int(l[6]))
            delta_s.append(int(l[7]))
            last_d.append(d[i]+delta_d[i]*(n[i]-1))
            td=d[i]
            for j in range(n[i]):
                if td in shedule:
                    shedule[td].append(i)
                else :
                    shedule[td]=list()
                    shedule[td].append(i)
                td+=delta_d[i]
        #print(shedule)
        for i in range(max(last_d)+1) :
            if i in shedule :
                for tribe in shedule[i] :
                    if wall.attack(w[tribe], e[tribe], s[tribe]) == 1 :
                            counter+=1
                for tribe in shedule[i]:
                    wall.build(w[tribe], e[tribe], s[tribe])
                    s[tribe]+=delta_s[tribe]
                    w[tribe]+=delta_p[tribe]
                    e[tribe]+=delta_p[tribe]

        
        print('Case #{}: {}'.format(k,counter))


if __name__ == '__main__':
    main()
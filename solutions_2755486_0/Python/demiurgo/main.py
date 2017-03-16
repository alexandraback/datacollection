#######################
##     Google Jam
##    Python template
##
##       by fxxf
##############


def timeIt(f):
    from time import clock

    def wrap(*args, **kwargs):
        t = clock()
        ret = f(*args, **kwargs)
        print f.__name__, clock()-t
        return ret
    return wrap


class Tribe:

    def __init__(self, d, N, w, e, s, delta_d, delta_p, delta_s):
        
        self.curr_d = 0

        self.d = d
        self.N = N

        self.n = 0

        self.w = w * 10
        self.e = e * 10
        self.s = s

        self.delta_d = delta_d
        self.delta_p = delta_p * 10
        self.delta_s = delta_s

        pass

    def next(self):

        if self.n < self.N:

            if self.curr_d == self.d:
                # attack
                ret = self.w, self.e, self.s
                # update
                self.n += 1
                self.w += self.delta_p
                self.e += self.delta_p

                self.s += self.delta_s
                self.d += self.delta_d

                self.curr_d += 1
                return ret
            else:
                self.curr_d += 1
                return 0,0,0

        else:
            return None
        pass


class Wall:
    successful_attacks = 0
    update_data = dict()

    def __init__(self):
        self.map = dict()


    def attack(self, tribe_stats):

        if tribe_stats:

            w, e, s = tribe_stats
            if s == 0: return

            # print tribe_stats

            for i in xrange(w, e, 5):
                # if (w,e) == (20,30):
                #     print i, self.map[i] if i in self.map else None



                if i not in self.map:
                    self.successful_attacks += 1
                    # print "arato"
                    for i in xrange(w, e, 5):
                        self.update_data[i] = s
                    return
                else:
                    if self.map[i] < s:
                        self.successful_attacks += 1
                        # print 'arato'
                        for i in xrange(w, e, 5):
                            self.update_data[i] = max(s, self.update_data[i]) if i in self.update_data else s
                        return
            # print "Nothing"                   
            pass

    def update(self):
        for k,v in self.update_data.iteritems():
            if k not in self.map or self.map[k] < v:
                    self.map[k] = v
        self.update_data.clear()




@timeIt
def main():
    from argparse import ArgumentParser

    parser = ArgumentParser()
    parser.add_argument("input", help="The input file")
    args = parser.parse_args()

    with open(args.input, 'r') as input, open("./output.out", "w") as output:

        ## _----------____ INSERT CODE BELOW _____------------_
        CASES = int(input.readline())

        for c in xrange(1, CASES + 1):

            print str(c) + '\n'
            tribes_n = int(input.readline().strip())

            tribes = []
            for i in xrange(0, tribes_n):
                tribes.append(Tribe(*map(int, input.readline().split())))
                pass

            wall = Wall()


            tribeStats = filter(None,  [x.next() for x in tribes])


            while tribeStats:
                # print '\n',tribeStats
                
                for stats in tribeStats:
                    wall.attack(stats)
                wall.update()
                tribeStats = filter(None,  [x.next() for x in tribes])


            attacks = wall.successful_attacks 
            
            # print attacks
            output.write("Case #%(c)i: %(attacks)i\n" % locals())
            pass

        ## _----------____ INSERT CODE ABOVE _____------------_
        pass
    return


if __name__ == '__main__':
    main()
    pass

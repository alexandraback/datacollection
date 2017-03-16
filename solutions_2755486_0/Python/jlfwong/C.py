import sys
import collections

class WallSegment(object):
    def __init__(self, w, e, s, l='?'):
        self.w = w
        self.e = e
        self.s = s
        self.l = l

    def attack_succeeds(self, atk):
        return (
            atk.w < self.e < atk.e or
            atk.w < self.w < atk.e or
            self.w < atk.e < self.e or
            self.w < atk.w < self.e
        ) and self.s < atk.s

    def __repr__(self):
        return '<%s %s^%s %s>' % (self.w, self.l, self.s, self.e)

class Attack(object):
    def __init__(self, w, e, s):
        self.w = w
        self.e = e
        self.s = s

    def __repr__(self):
        return '<!(%s ^%s %s)>' % (self.w, self.s, self.e)

class Wall(object):
    def __init__(self):
        self.segments = [WallSegment(
            w=-float('inf'),
            e=float('inf'),
            s=0
        )]

    def attack_succeeds(self, atk):
        for segment in self.segments:
            if segment.attack_succeeds(atk):
                return True

        return False

    def fortify(self, atk):
        next_segments = []

        for segment in self.segments:
            if segment.attack_succeeds(atk):
                if atk.w > segment.w:
                    next_segments.append(WallSegment(
                        w=segment.w,
                        e=atk.w,
                        s=segment.s,
                        l='L'
                    ))

                next_segments.append(WallSegment(
                    w=max(atk.w, segment.w),
                    e=min(atk.e, segment.e),
                    s=atk.s,
                    l='v'
                ))

                if atk.e < segment.e:
                    next_segments.append(WallSegment(
                        w=atk.e,
                        e=segment.e,
                        s=segment.s,
                        l='R'
                    ))
            else:
                next_segments.append(segment)

        self.segments = next_segments


casenum = 1
def doit(data):
    global casenum

    N = int(data.pop(0))

    attacks = collections.defaultdict(list)

    for i in range(N):
        di, ni, wi, ei, si, delta_di, delta_pi, delta_si = [int(x) for x in data.pop(0).split(' ')]

        for i in range(ni):
            attacks[di + i * delta_di].append(Attack(
                w=wi + delta_pi * i,
                e=ei + delta_pi * i,
                s=si + delta_si * i
            ))

    wall = Wall()
    ans = 0

    print >> sys.stderr, attacks

    for attack_day in attacks:
        print >> sys.stderr, 'DAY %d' % attack_day

        # Simulate Attacks
        for cur_attack in attacks[attack_day]:
            if wall.attack_succeeds(cur_attack):
                print >> sys.stderr, cur_attack, 'SUCCESS'
                ans += 1
            else:
                print >> sys.stderr, cur_attack, 'FAILURE'

        print >> sys.stderr, wall.segments

        # Fortify Wall
        for cur_attack in attacks[attack_day]:
            wall.fortify(cur_attack)
            print >> sys.stderr, cur_attack, 'FORTIFY'
            print >> sys.stderr, wall.segments

    print 'Case #%d: %s' % (casenum, ans)
    casenum += 1

raw = [x.strip() for x in sys.stdin.readlines()]

ZZZ = int(raw[0])
data = raw[1:]
for case in range(ZZZ):
    doit(data)

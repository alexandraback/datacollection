import sys

def solve(cars):
    # sort cars by speed
    N = len(cars)
    cars = [(c.speed, c) for c in cars]
    cars.sort()
    cars = [c for (junk, c) in cars]

    best_time = None

    for slow_idx in xrange(len(cars)):
        # for the slowest car, find when the other cars impact it.
        impacts = [collision(cars[slow_idx], cars[idx])
                   for idx in xrange(slow_idx, N)]
        impacts = [x for x in impacts if x]
        hits = [x[0] for x in impacts]
        ends = [x[1] for x in impacts]
        hits.sort()
        ends.sort()

        M = len(hits)
        
        h_idx = 0
        while h_idx < M and hits[h_idx] < 0:
            h_idx += 1
            
        e_idx = 0
        while e_idx < M and ends[e_idx] < 0:
            e_idx += 1

        count = 0

        while h_idx < M:
            if hits[h_idx] == ends[e_idx]:
                # cars pass at same time
                h_idx += 1
                e_idx += 1
            elif hits[h_idx] < ends[e_idx]:
                time = hits[h_idx]
                h_idx += 1
                count += 1
                if count > 1 and (best_time is None or time < best_time):
                    best_time = time
            else:
                count -= 1
                e_idx += 1
    return best_time
                
                    
                
        
    
                
                    


def collision(a, b):

    distance_delta = a.position - b.position
    speed_delta = b.speed - a.speed

    # if a is more than 5 meters ahead, and is slower
    if distance_delta > -5 and speed_delta > 0:
        # Cars collide from the time the from of the back one
        # hits the back of the front one, until, etc.
        # only call if the back one is faster!
        impact = (distance_delta - 5.0) / speed_delta
        end = (distance_delta + 5.0) / speed_delta
        return impact, end
    else:
        return None
    
        

class Car(object):
    def __init__(self, lane, speed, position):
        self.speed, self.position = speed, position
    def __repr__(self):
        return "Car(speed=%d, pos=%d)" % (self.speed, self.position)
    

def main(fp):
    T = int(fp.readline())
    for case in xrange(1,T+1):
        N = int(fp.readline().strip())
        cars = []
        for kk in xrange(N):
            tmp = fp.readline().strip().split()
            cars.append(Car(tmp[0], int(tmp[1]), int(tmp[2])))

        r = solve(cars)
        if r is None:
            r = "Possible"
        else:
            r = "%f" % r
        print "Case #%d: %s" % (case, r)

if __name__ == "__main__":
    import sys
    main(sys.stdin)




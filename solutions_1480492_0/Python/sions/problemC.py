import sys
import os
import math
import fractions
import functools
import time

class memoized(object):
    '''Decorator. Caches a function's return value each time it is called.
    If called later with the same arguments, the cached value is returned 
    (not reevaluated).
    '''
    def __init__(self, func):
        self.func = func
        self.cache = {}
    def __call__(self, *args):
        try:
            return self.cache[args]
        except KeyError:
            value = self.func(*args)
            self.cache[args] = value
            print "###", args
            return value
        except TypeError:
            # uncachable -- for instance, passing a list as an argument.
            # Better to not cache than to blow up entirely.
            return self.func(*args)
    def __repr__(self):
        '''Return the function's docstring.'''
        return self.func.__doc__
    def __get__(self, obj, objtype):
        '''Support instance methods.'''
        return functools.partial(self.__call__, obj)
  
def case_iterator(path):
    with file(path) as f:
        lines = iter(f)
        n = int(lines.next())
        
        yield n
        
        for i in range(1, 1 + n):
            yield i, read_case(lines)
            
def read_case(lines):
    as_str = lines.next()
    n = int(as_str.strip())
    cars = []
    for _ in xrange(n):
        lane, speed, pos = lines.next().strip().split()
        
        cars.append(dict(lane=lane, speed=float(speed), pos=float(pos)))
     
    assert len(cars) == n
    return cars

def get_pos(car):
    return car['lane'], car['pos'] 

DELTA = 1e-10

def next_event(cars):
    next_t = None
    next_index = None
    
    for i in xrange(len(cars) - 1):
        car_a, car_b = cars[i: i + 2]
        if car_a['lane'] != car_b['lane']:
            continue
        if car_a['speed'] <= car_b['speed']:
            continue
        
        d = car_b['pos'] - car_a['pos']
        if d - 5 <= 0:
            continue
        
        t = (d - 5) / (car_a['speed'] - car_b['speed'])
        if next_t is None or t < next_t:
            next_t = t
            next_index = i
    
#    print next_t, next_index        
    return next_t, next_index

lane_switch = {'L': 'R', 'R': 'L'}
def switch_lane(car):
    car['lane'] = lane_switch[car['lane']]
    
def is_colliding(car_a, car_b):
    assert car_a['pos'] <= car_b['pos']
    return car_a['pos'] + 5 >= car_b['pos']

def update(cars, dt):
    for car in cars:
        car['pos'] += car['speed'] * dt
        
    
    limits = [(car['pos'], car['pos'] + 5, car) for car in cars]
    limits.sort()
#    for i in xrange(len(limits) - 2):
#        colliding = limits[i: i + 3]
#        if abs(colliding[0][1] - colliding[-1][0]) < 1e-5:
#            return True, cars
#    for i in xrange(len(limits) - 1):
#        if abs(limits[i][2] - limits[i + 1][1]) < DELTA:
#            if any(j for j in limits if j[0] != limits[i][0] and 
#                   abs(j[1] - limits[i][1]) < 5 + DELTA):
#                
#                return True, cars

    for i in xrange(len(limits) - 1):
        start, end, car = limits[i]
        found = False
        for j in xrange(i + 1, len(limits)):
            a_start, a_end, a_car = limits[j]
            if a_start - end > DELTA:
                break
            if car['lane'] == a_car['lane']:
                found = True
                
        if found:
            colliding = any(k for k in limits if k[2]['lane'] != car['lane']
                            and abs(k[1] - start) < 5 + DELTA)
            if colliding:
                return True, cars
            switch_lane(car)
                
#    print 'limits', limits
        
#    for i in xrange(len(limits) - 1):
#        if abs(limits[i][2] - limits[i+1][1]) < DELTA:
#            car_a = limits[i][-1]
#            car_b = limits[i+1][-1]
#            if car_a['lane'] == car_b['lane']:
#                switch_lane(car_a)
#    
    cars = sorted(cars, key=get_pos)
    
    return False, cars 
    
def solve(case):
    cars = case
    
    if len(cars) <= 2:
        return 'Possible'
    
    t = 0
    cars = sorted(cars, key=get_pos)
    
    while True:
#        pprint(cars)
        dt, next_index = next_event(cars)
        if dt is None:
            break
        
        crash, cars = update(cars, dt)
        t += dt
        if crash:
            return t 
        
    return 'Possible'
 
def pprint(cars):
    print ' '.join(['%s %s %s' % (i['lane'], i['pos'], i['speed']) for i in cars])
 
trace = False 
debug = True
    
def main():
    try:
        path, = sys.argv[1:]
    except:
        sys.exit('usage: %s <input file>' % (sys.argv[0],))
    
    iterator = case_iterator(path)
    n = iterator.next()

    outpath = os.path.splitext(path)[0] + '.out'

    with file(outpath, 'wt') as fout:
        start = time.time()
        for i, case in iterator:
            out_line = 'Case #%d: %s' % (i, solve(case))
            print >> fout, out_line
            if debug:
                print out_line
            
            total = time.time() - start
            if trace:
                print >> sys.stderr, ('remaining: %.2f seconds' %  
                                      ((n - i) * (total / i),))

if __name__ == '__main__':
    main()

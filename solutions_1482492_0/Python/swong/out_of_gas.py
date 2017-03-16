from math import sqrt
def solve( D, N, T, X, a ):

   time = 0.0
   d0 = D
   v0 = 0.0
   for n in range(1,N):
      #print "time={}, d0={}, v0={}".format( time, d0, v0 )

      dt = T[n] - T[n-1]
      dx = X[n] - X[n-1]
      t = T[n]
      x = X[n]

      # Check if we're passing the end
      if x > D:
         m = dx/dt
         b = x - m*t

         # Update x and dt
         t_int = (D-b)/m
         x  = D
         dt = t_int - T[n-1]
         if t_int < 0: break

      dGrav = d0 - v0*dt - 0.5*a*dt*dt

      #print "dGrav={}, x={}".format( dGrav, x )
      if dGrav > (D-x):
         # Falling is slower than following
         #print "Falling"
         time += dt
         d0 = dGrav
         v0 += dt*a
      else:
         # Following is slower than falling
         #print "Following"
         time += dt
         d0 = D-x
         v0 = 0.0
      #print "d0={}, v0={}, dt={}".format( d0, v0, dt )
   
   # Check if we still need to fall
   #print "End of car, d0={}".format(d0)
   if d0 > 0:
      t_quad = (-v0 + sqrt( v0*v0 + 2*a*d0 )) / a
      #print "t_quad={}".format( t_quad )
      time += t_quad

   print time


from sys import stdin

T = int( stdin.readline() )
for t in range(T):
   tokens = stdin.readline().split()
   D = float( tokens[0] )
   N = int( tokens[1] )
   #A = int( tokens[2] )
   T = []
   X = []
   for n in range(N):
      tokens = [ float(i) for i in stdin.readline().split() ]
      T.append( tokens[0] )
      X.append( tokens[1] )
   A = [ float(i) for i in stdin.readline().split() ]
   #print A

   print "Case #{}:".format( t+1 )
   for a in A:
      solve(D,N,T,X,a)

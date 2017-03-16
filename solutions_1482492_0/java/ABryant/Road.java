import java.util.Scanner;

class Road
{
  public static void main(String... args)
  {
    Scanner sc = new Scanner(System.in);
    int tests = sc.nextInt();
    for (int test = 1; test <= tests; test++)
    {
      double dist = sc.nextDouble();
      int n = sc.nextInt();
      int a = sc.nextInt();
      double[] ts = new double[n];
      double[] xs = new double[n];
      for (int i = 0; i < n; i++)
      {
        ts[i] = sc.nextDouble();
        xs[i] = sc.nextDouble();
      }
      double[] as = new double[a];
      for (int i = 0; i < a; i++)
      {
        as[i] = sc.nextDouble();
      }
      System.out.println("Case #" + test + ":");
      for (int i = 0; i < a; i++)
      {
        System.out.println(solve(dist, ts, xs, as[i]));
      }
    }
  }

  public static double solve(double dist, double[] ts, double[] xs, double a)
  {
    double pos = 0;
    double vel = 0;
    double lastT = 0;
    double lastX = xs[0];
    for (int i = 0; i < ts.length; i++)
    {
      double dt = ts[i] - lastT;
      double newPos = vel * dt + 0.5 * a * dt * dt;
      if (newPos > xs[i])
      {
        if (xs[i] >= dist)
        {
          // we are about to crash, but we reach home before the end of this section
          // so find which comes first, crash or home
          // home:
          double finalT1 = (-vel + Math.sqrt(vel*vel - 2 * a * (pos - dist))) / a;
          double finalT2 = (-vel - Math.sqrt(vel*vel - 2 * a * (pos - dist))) / a;
          double finalT = finalT1 < 0 ? finalT2 : finalT2 < 0 ? finalT1 : Math.min(finalT1, finalT2);
          // crash:
          double cvel = (xs[i] - lastX) / dt;
          double dv = vel - cvel;
          double crashT1 = - (-dv + Math.sqrt(dv*dv - 2 * a * (pos - lastX))) / a;
          double crashT2 = - (-dv - Math.sqrt(dv*dv - 2 * a * (pos - lastX))) / a;
          double crashT = crashT1 < 0 ? crashT2 : crashT2 < 0 ? crashT1 : Math.min(crashT1, crashT2);
          if (finalT < crashT)
          {
            return finalT;
          }
          return ((dist - lastX) / (xs[i] - lastX)) * dt + lastT;
        }
        pos = xs[i];
        vel = Math.max((xs[i] - lastX) / dt, Math.sqrt(2 * a * (xs[i] - lastX)));
      }
      else
      {
        if (newPos >= dist)
        {
          break;
        }
        pos = newPos;
        vel += a * dt;
      }
      //System.out.println("pos=" + pos + ", vel=" + vel + ", dist=" + dist);
      lastT = ts[i];
      lastX = xs[i];
    }
    double finalT1 = (-vel + Math.sqrt(vel*vel - 2 * a * (pos - dist))) / a;
    double finalT2 = (-vel - Math.sqrt(vel*vel - 2 * a * (pos - dist))) / a;
    //System.out.println("vel=" + vel + ", pos=" + pos + ", dist= " + dist + ", a=" + a + " -- finalT1=" + finalT1 + " finalT2=" + finalT2);
    if (finalT1 < 0 || Double.isNaN(finalT1))
    {
      return lastT + finalT2;
    }
    if (finalT2 < 0 || Double.isNaN(finalT2))
    {
      return lastT + finalT1;
    }
    return lastT + Math.min(finalT1, finalT2);
  }
}
